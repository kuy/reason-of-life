open Life;

module Page = {
  include ReactRe.Component.Stateful;
  type props = unit;
  type state = { time: int, data: Board.t };
  let name = "Page";
  let getInitialState _ /* props */ =>
    { time: 0, data:
      Board.of_matrix [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
      ]
    };
  let handleClick { state } _ =>
    Some { ...state, time: state.time + 1, data: Board.next state.data };
  let render { state, updater } => {
    <div>
      <Board data=state.data />
      <button onClick=(updater handleClick)>(ReactRe.stringToElement "Tick")</button>
      (ReactRe.stringToElement ("Time: " ^ (string_of_int state.time)))
    </div>
  };
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
