external glamor : 'glamor = "glamor" [@@bs.module];

let make = ReactDOMRe.Style.make;

let global tag styles => glamor##css##global tag styles;
let className styles => glamor##css styles;
let merge s1 s2 => glamor##css s1 s2;

let body = make
  background::"#efefef"
  color::"#838383"
  display::"flex"
  height::"calc(100vh - 3em)"
  justifyContent::"center"
  marginTop::"3em"
  ();

let () = global "body" body;
