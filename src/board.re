module Board = {
  include ReactRe.Component;
  /* type boardData = list list int; */
  type boardData = list int;
  type props = { data: boardData };
  let name = "Board";
  let render { props, updater } => {
    let row =
      props.data
      |> List.map (fun s => <td>(ReactRe.stringToElement (string_of_int s))</td>)
      |> Array.of_list
      |> ReactRe.arrayToElement;
    <table>
      <tbody>
        <tr>(row)</tr>
      </tbody>
    </table>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::data => wrapProps { data: data };
