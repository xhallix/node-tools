
/**
 * @Todo - write real tests
 */
const datatypes = require('../build/Release/datatypes');
const stringutils = require('../build/Release/stringutils');


console.log('DATATYPES: \n');
console.log(datatypes.isInteger("22")); // false
console.log(datatypes.isFloat(2.22)); // true
console.log(datatypes.inArray([1,2,3],5)); // false
console.log(datatypes.inArray([1,2,3],2)); // true
console.log(datatypes.inArray([1,"foobar",3],"foobar")); // true
console.log(datatypes.inArray([{'1':1}],{'1':1})); // true
console.log('-------------------- END DATATYPES ----------------------- \n');


console.log('STRINGUTILS: \n');
console.log(stringutils.snakeCase('fooBar')); // returns foo_bar
console.log('-------------------- END STRINGUTILS ----------------------- \n');