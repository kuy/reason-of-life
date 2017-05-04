module Page = {
  include ReactRe.Component.Stateful;
  type props = unit;
  type state = { gen: int, pause: bool, data: Board.t };
  let name = "Page";
  let getInitialState _ =>
    { gen: 0, pause: true, data:
      Board.of_matrix [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
      ]
    };
  let handleTick { state } _ =>
    Some { ...state, gen: state.gen + 1, data: Board.next state.data };
  let handlePause { state } _ =>
    Some { ...state, pause: not state.pause };
  let rec handleTimeout { updater, state } _ => {
    Js.Global.setTimeout (updater handleTimeout) 1000;
    if (not state.pause) {
      Some { ...state, gen: state.gen + 1, data: Board.next state.data }
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
      <Flexbox>
        <Board data=state.data />
        <Flexbox dir=(Flexbox.Column)>
          <div>
            (ReactRe.stringToElement ("Generation: " ^ (string_of_int state.gen)))
          </div>
          <div>
            (ReactRe.stringToElement ("Timer: " ^ (state.pause ? "Paused" : "Running")))
          </div>
          <div>
            <button onClick=(updater handleTick)>(ReactRe.stringToElement "Tick")</button>
            <button onClick=(updater handlePause)>(ReactRe.stringToElement (state.pause ? "Resume" : "Pause"))</button>
          </div>
        </Flexbox>
      </Flexbox>
    </div>
  };
};

include ReactRe.CreateComponent Page;

let createElement = wrapProps ();
