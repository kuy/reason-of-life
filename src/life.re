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
