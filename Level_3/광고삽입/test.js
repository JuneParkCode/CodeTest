function h() {
	let i = 0;
	while (1) {
		if (i === Number.MAX_SAFE_INTEGER) {
			i = 0;
		}
		console.log(i++);
	}
}

console.log(h());
