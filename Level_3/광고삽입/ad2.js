function solution(play_time, adv_time, logs) {
	// 시간을 보다 쉽게 다루기 위해서 정수형으로 변환한다.
	const intPlayTime = time2int(play_time);
	const intAdvTime = time2int(adv_time);
	// advTime 이 playTime 보다 긴 경우, 처음부터 트는 것이 가장 합당하다.
	if (intPlayTime <= intAdvTime) return "00:00:00";

	// 각 시작, 끝 시간에 대해서 조사를 하는 것이 바람직하다.
	const timeSet = new Set();

	// log에 포함된 시간값 또한, 정수로 변환하여 다룬다.
	const REG = RegExp("(?<s_time>[0-9]{2}:[0-9]{2}:[0-9]{2})-(?<e_time>[0-9]{2}:[0-9]{2}:[0-9]{2})");
	const intLogs = logs
		.map((elem) => {
			const t = elem.match(REG).groups;
			const [sTime, eTime] = [time2int(t.s_time), time2int(t.e_time)];
			timeSet.add(sTime);
			timeSet.add(eTime);
			return [sTime, eTime];
		})
		.sort((a, b) => {
			return a[0] - b[0];
		});
	// 속도 향상을 위해 idx 저장용...
	const timeMap = new Map();
	// Set to Array
	const temp = Array.from(timeSet).sort((a, b) => {
		return +a - +b;
	});
	// bar은 각 시간대에 대해서 [startTime, count, duration] 으로 구성.
	const bar = temp.map((elem, idx) => {
		timeMap.set(elem, idx);
		return [elem, 0, idx < temp.length - 1 ? temp[idx + 1] - elem : 0];
	});
	// log를 바탕으로 각 시간대의 view 횟수 기록.
	intLogs.forEach(([sTime, eTime]) => {
		for (let i = timeMap.get(sTime); bar[i][0] < eTime; i++) {
			if (sTime <= bar[i][0] && bar[i][0] < eTime) {
				bar[i][1]++;
			}
		}
	});
	// 각 시간대별 누적 시간 계산.
	let max = 0;
	let resInt = 0;
	for (let i = 0; i < bar.length - 1; i++) {
		const sTime = bar[i][0];
		const eTime = sTime + intAdvTime;
		let acc = 0;
		for (let j = i; j < bar.length; j++) {
			const [t, c, d] = bar[j];
			if (t >= eTime) break;
			if (t + d <= eTime) {
				acc += c * d;
			} else {
				acc += (eTime - t) * c;
			}
		}
		if (max < acc) {
			max = acc;
			resInt = sTime;
		}
	}
	return int2time(resInt);
}

function time2int(time) {
	const REG = RegExp("(?<h>[0-9]{2}):(?<m>[0-9]{2}):(?<s>[0-9]{2})");
	const times = time.match(REG).groups;
	const result = times.h * 3600 + times.m * 60 + +times.s;
	return +result;
}
function int2time(n) {
	const h = Math.floor(n / 3600);
	const m = Math.floor((n - h * 3600) / 60);
	const s = n - h * 3600 - m * 60;
	return `${addZero(h)}:${addZero(m)}:${addZero(s)}`;
}
function addZero(n) {
	const str = n.toString();
	return str.length <= 1 ? "0" + str : str;
}

// play time 내에서 검색
// play time -> int로 변환하자.
// h*3600 + m *60 + s
// log 에서 s_time, e_time으로 나눠서 각각 저장함.
// 추석 트래픽에서 적용한 알고리즘과 유사하게 적용하거나, sliding window를 적용하는 것이 바람직하다.
// window의 크기는 adv_time
