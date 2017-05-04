'use strict';

var webpack = require('webpack');

module.exports = {
  entry: './src/index.re',
  module: {
    rules: [{
      test: /\.(re|ml)$/,
      use: 'bs-loader',
      exclude: /node_modules/
    }]
  },
  resolve: {
    extensions: ['.re', '.ml', '.js']
  },
  output: {
    path: __dirname + '/public',
    filename: 'bundle.js',
    publicPath: '/in-memory'
  },
  plugins: (process.env.NODE_ENV === 'production') ? [
    new webpack.DefinePlugin({
      'process.env': { NODE_ENV: JSON.stringify('production') }
    }),
    new webpack.optimize.UglifyJsPlugin({
      compress: { warnings: false }
    })
  ] : []
};
