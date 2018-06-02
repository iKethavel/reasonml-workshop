type player =
  | Circle
  | Cross;

type field = option(player);

type board = list(field);

let fieldToStr = value =>
  switch (value) {
  | None => "-"
  | Some(Circle) => "O"
  | Some(Cross) => "X"
  };

type gameState =
  | Draw
  | Win(player)
  | Playing(player);
