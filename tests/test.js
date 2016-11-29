
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
console.log(stringutils.snakeCase('foo Bar')); // returns foo_bar
console.log('-------------------- END STRINGUTILS ----------------------- \n');


var process = require('process');



console.log('-------------------- PERF STRINGUTILS ----------------------- \n');
var hrstart = process.hrtime();
for(var x = 0; x < 100000; x ++) {
    stringutils.snakeCase('fooBar')
}
var hrend = process.hrtime(hrstart);
console.log("C function ", hrend[0], hrend[1]/1000000);


var hrstart = process.hrtime();
for(var x = 0; x < 100000; x ++) {
    'fooBar'.replace(/\w\S*/g, function(txt){return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();})
}
var hrend = process.hrtime(hrstart);
console.log("plain function ", hrend[0], hrend[1]/1000000);
console.log('-------------------- PERF STRINGUTILS END ----------------------- \n');