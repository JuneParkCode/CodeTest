function solution(play_time, adv_time, logs) {
	// 시간을 보다 쉽게 다루기 위해서 정수형으로 변환한다.
	const intPlayTime = time2int(play_time);
	const intAdvTime = time2int(adv_time);
	// advTime 이 playTime 보다 긴 경우, 처음부터 트는 것이 가장 합당하다.
	if (intPlayTime <= intAdvTime) return "00:00:00";

	// 각 시작, 끝 시간에 대해서 조사를 하는 것이 바람직하다.
	const timeSet = new Set();

	// log에 포함된 시간값 또한, 정수로 변환하여 다룬다.
	const l = [];
	const REG = RegExp("(?<s_time>[0-9]{2}:[0-9]{2}:[0-9]{2})-(?<e_time>[0-9]{2}:[0-9]{2}:[0-9]{2})");
	logs.forEach((elem) => {
		const t = elem.match(REG).groups;
		const [sTime, eTime] = [time2int(t.s_time), time2int(t.e_time)];
		l.push([sTime, eTime]);
		timeSet.add(sTime);
	});
	const intLogs = l.sort((a, b) => {
		if (a[0] < b[0]) {
			return -1;
		} else if (a[0] === b[0]) {
			return 0;
		} else {
			return 1;
		}
	});
	// time  ~ time + advTime 내에 해당 재생 시간이 포함되면 누적 시간에 포함함.
	const checkTimes = Array.from(timeSet);
	let max = -1;
	let intResult = 0;
	checkTimes.forEach((checkTime) => {
		const cStartTime = +checkTime;
		const cEndTime = +checkTime + intAdvTime;
		let accTime = 0;
		for (const [sTime, eTime] of intLogs) {
			if (cEndTime < sTime) break;
			else if (eTime < cStartTime) continue;
			if (cStartTime <= sTime && eTime <= cEndTime) {
				accTime += eTime - sTime;
			} else if (cStartTime <= sTime && cEndTime <= eTime && sTime <= cEndTime) {
				accTime += cEndTime - sTime;
			} else if (sTime <= cStartTime && eTime <= cEndTime && cStartTime <= eTime) {
				accTime += eTime - cStartTime;
			}
		}
		if (max < accTime) {
			max = accTime;
			intResult = checkTime;
		} else if (max === accTime) {
			intResult = intResult > checkTime ? checkTime : intResult;
		}
	});
	// console.log(int2time(intResult),int2time(max));
	return int2time(intResult);
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
