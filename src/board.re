module Board = {
  include ReactRe.Component.Stateful;
  type rowData = list int;
  type boardData = list rowData;
  type props = unit;
  type state = { data: boardData };
  let name = "Board";
  let getInitialState _ /* props */ =>
    { data: [[1, 1, 0], [1, 0, 0], [0, 0, 0]] };
  let renderRow data =>
    data
    |> List.map (fun s => <td>(ReactRe.stringToElement (string_of_int s))</td>)
    |> Array.of_list
    |> ReactRe.arrayToElement;
  let render { state, updater } => {
    let board =
      state.data
      |> List.map (fun d => <tr>(renderRow d)</tr>)
      |> Array.of_list
      |> ReactRe.arrayToElement;
    <table>
      <tbody>(board)</tbody>
    </table>
  };
};

include ReactRe.CreateComponent Board;

let createElement = wrapProps ();
