    /* <Board data=[[1, 0], [0, 1]] />; */

module Page = {
  include ReactRe.Component;
  type props = unit;
  let name = "Page";
  let render { props, updater } =>
    <Board data=[0,1,2,3,4] />;
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
