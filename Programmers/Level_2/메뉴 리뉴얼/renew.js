function solution(orders, course) {
	const resMap = new Map();
	// 메뉴 순서 정렬
	const refine = orders.map((order) => {
		return order.split("").sort().join("");
	});
	// Map을 통해서 조합 빈도 계산
	refine.forEach((order) => {
		course.forEach((n) => {
			combination(resMap, order, "", n, 0, 0, n);
		});
	});
	// 계산을 용이하게 하기 위해 Map -> Array
	const arr = Array.from(resMap);
	// 계산을 용이하게 하기 위해 코스 개수별로 저장
	const a = course.map((n) => {
		return arr.filter((elem) => elem[0].length === n);
	});
	// 각 코스 개수마다 최다 빈도를 알아냄
	const max = a
		.map((elem) => {
			return elem.reduce((res, cur) => {
				return res > cur[1] ? res : cur[1];
			}, 0);
		})
		.map((n) => (n > 1 ? n : 0));
	// 최다 빈도에 해당되는 요소들을 추려내고 결과물에 맞게 정제함
	const result = a
		.map((elem, idx) => {
			return elem
				.filter((cur) => cur[1] === max[idx])
				.map((elem) => {
					return elem[0];
				});
		})
		.flat()
		.sort();

	return result;
}
function combination(resMap, str, res, r, idx, depth, target) {
	if (r === 0) {
		if (res.length === target) {
			const frequency = resMap.get(res);
			resMap.set(res, (frequency ? frequency : 0) + 1);
		}
	} else if (depth === str.length) {
		return;
	} else {
		combination(resMap, str, res + str[idx], r - 1, idx + 1, depth + 1, target);
		combination(resMap, str, res, r, idx + 1, depth + 1, target);
	}
}
