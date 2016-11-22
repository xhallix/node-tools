
/**
 * @Todo - write real tests
 */
const datatypes = require('../build/Release/datatypes');


console.log(datatypes.isInteger("22")); // false
console.log(datatypes.isFloat(2.22)); // true
console.log(datatypes.inArray([1,2,3],5)); // false
console.log(datatypes.inArray([1,2,3],2)); // true
console.log(datatypes.inArray([1,"foobar",3],"foobar")); // true
console.log(datatypes.inArray([{'1':1}],{'1':1})); // true