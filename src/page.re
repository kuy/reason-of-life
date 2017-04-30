open Life;

module Page = {
  include ReactRe.Component.Stateful;
  type props = unit;
  type state = { time: int, pause: bool, data: Board.t };
  let name = "Page";
  let getInitialState _ =>
    { time: 0, pause: true, data:
      Board.of_matrix [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
      ]
    };
  let handleTick { state } _ =>
    Some { ...state, time: state.time + 1, data: Board.next state.data };
  let handlePause { state } _ =>
    Some { ...state, pause: not state.pause };
  let rec handleTimeout { updater, state } _ => {
    Js.Global.setTimeout (updater handleTimeout) 1000;
    if (not state.pause) {
      Some { ...state, time: state.time + 1, data: Board.next state.data }
    } else {
      None
    }
  };
  let componentDidMount { updater, state } => {
    Js.Global.setTimeout (updater handleTimeout) 1000;
    None
  };
  let render { state, updater } => {
    <div>
      <Board data=state.data />
      <div>
        <button onClick=(updater handleTick)>(ReactRe.stringToElement "Tick")</button>
        (ReactRe.stringToElement ("Tick: " ^ (string_of_int state.time)))
      </div>
      <div>
        <button onClick=(updater handlePause)>(ReactRe.stringToElement (state.pause ? "Resume" : "Pause"))</button>
        (ReactRe.stringToElement ("Timer: " ^ (state.pause ? "Paused" : "Running")))
      </div>
    </div>
  };
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
