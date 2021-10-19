function solution(info, query) {
	const infos = info
		.map((elem) => elem.split(" "))
		.map((elem) => {
			return {
				language: elem[0],
				group: elem[1],
				career: elem[2],
				food: elem[3],
				score: elem[4],
			};
		});
	const qInfo = query.map((q) =>
		q
			.split(" ")
			.filter((elem) => elem !== "and")
			.map((elem) => {
				if (elem === "-") return true;
				else return elem;
			})
	);
	return qInfo.map((q) => {
		const qMap = new Map();
		if (qMap.has(q)) {
			return qMap.get(q);
		} else {
			const res = infos.filter((info) => {
				if (
					(q[0] === true || info.language === q[0]) &&
					(q[1] === true || info.group === q[1]) &&
					(q[2] === true || info.career === q[2]) &&
					(q[3] === true || info.food === q[3]) &&
					(q[4] === true || +info.score > +q[4])
				) {
					return true;
				} else {
					return false;
				}
			}).length;
			qMap.set(q, res);
			return res;
		}
	});
}
