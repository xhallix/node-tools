# Node Tools

Useful tools, written in c++ for node js.

## Notes

This is more a fun, then a real project - I'd like to play around with node modules

## Methods

```javascript
const datatypes = require('../build/Release/datatypes');
datatypes.isInteger("22");
datatypes.isFloat(2.22);
datatypes.inArray([1,2,3],2);
```

## Usage

1. Configure node-gyp (only once)
`$ node-gyp configure`

2. Build it
`$ node-gyp build` 

Do `node tests/test.js`
