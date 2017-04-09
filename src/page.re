module Page = {
  include ReactRe.Component.Stateful;
  type props = unit;
  type state = { time: int };
  let name = "Page";
  let getInitialState _ /* props */ => { time: 0 };
  let handleClick { state } _ => {
    Js.log "click";
    Some { ...state, time: state.time + 1 }
  };
  let render { state, updater } =>
    <div>
      <Board />
      <button onClick=(updater handleClick)>(ReactRe.stringToElement "Tick")</button>
      (ReactRe.stringToElement ("Time: " ^ (string_of_int state.time)))
    </div>;
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
