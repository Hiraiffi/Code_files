// var x="Hello World!!";

// var message="in global";
// console.log("global: message = " + message);

// var a = function() {
// 	var message = "inside a";
// 	console.log("a: message = " + message);
// 	function b () {
// 	console.log("b: message = " + message);
// }
// b();
// }


// a();
// var x;
// console.log(x);
// var sum=0;
// for(var i=0;i<10;i++)
// {
// 	sum+=i;
// }
// console.log(sum);

function makeMultiplier(multiplier) {
	var myFunc = function (x) {
		return multiplier * x;
	};

	return myFunc;
}

var mulitplyby3 = makeMultiplier(3);
console.log(mulitplyby3(10));