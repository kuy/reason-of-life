module Page = {
  include ReactRe.Component;
  type props = { answer: int };
  let name = "Page";
  let handleClick _ _ => {
    Js.log "answer";
    None
  };
  let render { props, updater } =>
    <div onClick=(updater handleClick)> (ReactRe.stringToElement (string_of_int props.answer)) </div>;
};

include ReactRe.CreateComponent Page;

let createElement ::answer => wrapProps { answer: answer };
