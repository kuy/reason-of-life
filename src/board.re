module Board = {
  include ReactRe.Component;
  type rowData = list int;
  type boardData = list rowData;
  type props = { data: boardData };
  let name = "Board";
  let renderRow data =>
    data
    |> List.map (fun s => <td>(ReactRe.stringToElement (string_of_int s))</td>)
    |> Array.of_list
    |> ReactRe.arrayToElement;
  let render { props, updater } => {
    let board =
      props.data
      |> List.map (fun d => <tr>(renderRow d)</tr>)
      |> Array.of_list
      |> ReactRe.arrayToElement;
    <table>
      <tbody>(board)</tbody>
    </table>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::data => wrapProps { data: data };
