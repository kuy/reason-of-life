module Page = {
  include ReactRe.Component;
  type props = unit;
  let name = "Page";
  let render { props, updater } =>
    <Board data=[[1, 1, 0], [1, 0, 0], [0, 0, 0]] />;
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
