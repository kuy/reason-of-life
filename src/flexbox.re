type direction = Column | Row;

let style_col = Styles.make
  display::"flex"
  flexDirection::"column"
  ();

let style_row = Styles.make
  display::"flex"
  flexDirection::"row"
  ();

let of_dir d =>
  switch d {
    | Column => style_col
    | Row => style_row
  } |> Styles.className;

module Flexbox = {
  include ReactRe.Component;
  type props = {
    dir: direction,
    children: list ReactRe.reactElement
  };
  let name = "Flexbox";
  let render { props: { dir, children } } => {
    <div className=(of_dir dir)>
      (ReactRe.listToElement children)
    </div>
  };
};

include ReactRe.CreateComponent Flexbox;

let createElement ::dir=Row ::children => wrapProps { dir, children } ::children;
