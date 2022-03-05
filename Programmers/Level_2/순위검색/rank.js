function solution(info, query) {
	const infos = [];
	const langs = [];
	const groups = [];
	const careers = [];
	const foods = [];
	const a = info
		.map((elem) => elem.split(" "))
		.map((elem) => {
			const p = {
				language: elem[0],
				group: elem[1],
				career: elem[2],
				food: elem[3],
				score: elem[4],
			};
			let l = langs.indexOf(p.language);
			let g = groups.indexOf(p.group);
			let c = careers.indexOf(p.career);
			let f = foods.indexOf(p.food);
			if (l === -1) {
				langs.push(p.language);
				infos.push([]);
				l = langs.length - 1;
			}
			while (infos.length === undefined || infos.length < l + 1) {
				infos.push([]);
			}
			if (g === -1) {
				groups.push(p.group);
				infos[l].push([]);
				g = groups.length - 1;
			}
			while (infos[l].length === undefined || infos[l].length < g + 1) {
				infos[l].push([]);
			}
			if (c === -1) {
				careers.push(p.career);
				infos[l][g].push([]);
				c = careers.length - 1;
			}
			while (infos[l][g].length === undefined || infos[l][g].length < c + 1) {
				infos[l][g].push([]);
			}
			if (f === -1) {
				foods.push(p.food);
				infos[l][g][c].push([]);
				f = foods.length - 1;
			}
			while (infos[l][g][c].length === undefined || infos[l][g][c].length < f + 1) {
				infos[l][g][c].push([]);
			}
			infos[l][g][c][f].push(p.score);
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
		let target;
		const l = langs.indexOf(q[0]);
		const g = groups.indexOf(q[1]);
		const c = careers.indexOf(q[2]);
		const f = foods.indexOf(q[3]);
		if (q[0] === true) {
			target = infos.flat(5);
		} else if (q[1] === true) {
			target = infos[l].flat(5);
		} else if (q[2] === true) {
			target = infos[l][g].flat(5);
		} else if (q[3] === true) {
			target = infos[l][g][c].flat(5);
		} else {
			target = infos[l][g][c][f].flat(5);
		}
		const res = target.filter((i) => {
			if (+i >= +q[4]) {
				return true;
			} else {
				return false;
			}
		}).length;
		return res;
	});
}
