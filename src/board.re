open Life;

type row = list Life.t;
type t = list row;

let selectRow row data =>
  switch (List.length data) {
    | 0 => None
    | h => {
      if (row <= (-1) || h <= row) {
        None
      } else {
        Some (List.nth data row)
      }
    }
  };

let selectCell col data =>
  switch data {
    | None => Dead
    | Some d =>
      switch (List.length d) {
        | 0 => Dead
        | w => {
          if (col <= (-1) || w <= col) {
            Dead
          } else {
            List.nth d col
          }
        }
      };
  };

let get data x y =>
  data
  |> selectRow y
  |> selectCell x;

let count data x y => {
  let surround = [
    ((-1), (-1)), (0, (-1)), (1, (-1)),
    ((-1),    0),            (1,    0),
    ((-1),    1), (0,    1), (1,    1)
  ];
  List.fold_right (fun (dx, dy) c => c + (Life.to_int @@ get data (x + dx) (y + dy))) surround 0
};

let next_cell data x y =>
  switch (get data x y) {
    | Alive =>
      switch (count data x y) {
        | 2 | 3 => Alive
        | _ => Dead
      }
    | Dead  =>
      switch (count data x y) {
        | 3 => Alive
        | _ => Dead
      }
  };

let next data =>
  List.mapi (fun y r => List.mapi (fun x _ => next_cell data x y) r) data;

let of_matrix src =>
  List.map (fun r => List.map (fun c => Life.of_int c) r) src;

module Board = {
  include ReactRe.Component;
  type props = { data: t };
  let name = "Board";
  let renderRow data =>
    data
    |> List.map (fun l => <td className=(Life.to_name l)>(ReactRe.stringToElement (Life.to_string l))</td>)
    |> Array.of_list
    |> ReactRe.arrayToElement;
  let render { props } => {
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
