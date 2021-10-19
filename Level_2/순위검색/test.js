class test {
	constructor() {
		this.test = "hello";
	}
	find() {
		return this;
	}
}
const obj = {
	test: "hello",
	find() {
		return this;
	},
};
const t = new test();
console.log("THIS: ", t.find());
console.log("Global: ", this);
console.log("OBJ: ", obj.find());
