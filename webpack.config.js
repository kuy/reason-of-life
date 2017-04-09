'use strict';

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
    filename: 'bundle.js',
    publicPath: '/in-memory'
  }
};
