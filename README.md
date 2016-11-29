# Node Tools

Useful tools, written in c++ for node js.

## Notes

This is more a fun, then a real project - I'd like to play around with node modules.
Further those methods will outperform every javascript/nodejs way.

## Methods

```javascript
const datatypes = require('../build/Release/datatypes');
const stringutils = require('../build/Release/stringutils');
datatypes.isInteger("22");
datatypes.isFloat(2.22);
datatypes.inArray([1,2,3],2);
stringutils.snakeCase('fooBar');
```

# Tests

Do `node tests/test.js` to the the results and be convinced by the performance boost

# Todo

- snake_case


## Usage

1. Configure node-gyp (only once)
`$ node-gyp configure`

2. Build it
`$ node-gyp build` 

