type t = Alive | Dead;

let to_string l =>
  switch l {
    | Alive => "1"
    | Dead  => "0"
  };

let to_int l =>
  switch l {
    | Alive => 1
    | Dead => 0
  };

let of_int l =>
  switch l {
    | 1 => Alive
    | 0 => Dead
  };

let cell = Styles.make
  width::"20px"
  height::"20px"
  () |> Styles.merge;

let alive = Styles.make
  color::"#3498db"
  backgroundColor::"#3498db"
  () |> cell |> Styles.className;

let dead = Styles.make
  color::"white"
  backgroundColor::"white"
  () |> cell |> Styles.className;

let to_name l =>
  switch l {
    | Alive => alive
    | Dead => dead
  };
