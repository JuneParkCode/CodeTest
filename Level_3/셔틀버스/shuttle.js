function solution(n, t, m, timetable) {
	const busTimeTable = getBusTimeTable(n, t);
	const lastBusTime = busTimeTable[busTimeTable.length - 1];
	const crewTimeTable = timetable
		.map((elem) => timeToInt(elem))
		.filter((elem) => lastBusTime >= elem)
		.sort();
}

// util
function timeToInt(time) {
	const h = +time.substr(0, 2);
	const m = +time.substr(3, 2);
	return h * 60 + +m;
}

function intToTime(num) {
	const h = Math.floor(num / 60);
	const m = num % 60;
	// 00:00 꼴로 바꾸기 위함
	const hour = h < 10 ? `0` + h : h;
	const min = m < 10 ? `0` + m : m;

	return `${hour}:${min}`;
}
// time -> m단위로 0~60*24으로 설정
// 09:00 = 60 * 9
function getBusTimeTable(n, t) {
	const START_TIME = 60 * 9;
	const busTimeTable = Array(n)
		.fill(0)
		.map((elem, idx) => START_TIME + idx * t);
	return busTimeTable;
}
