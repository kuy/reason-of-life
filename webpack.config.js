'use strict';

var webpack = require('webpack');

module.exports = {
  entry: './src/index.re',
  module: {
    rules: [{
      test: /\.(re|ml)$/,
      use: 'bs-loader'
    }]
  },
  resolve: {
    extensions: ['.re', '.ml', '.js']
  },
  output: {
    path: __dirname + '/public',
    filename: 'bundle.js'
  }
};
