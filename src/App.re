[%bs.raw {|require('./App.css')|}];

open Core;

type state = {
  board,
  gameState,
};

type action =
  | Move(int);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    board: [
      None,
      None,
      None,
      None,
      None,
      None,
      None,
      None,
      None,
    ],
    gameState: Playing(Cross),
  },
  reducer: (action, state) =>
    switch (action) {
    | Move(index) =>
      switch (state.gameState) {
      | Playing(Cross) =>
        ReasonReact.UpdateWithSideEffects(
          {
            ...state,
            board:
              state.board
              |> List.mapi((idx, field) =>
                   index == idx ? Some(Cross) : field
                 ),
            gameState: Playing(Circle),
          },
          (self =>
            Js.Promise.(
              Api.fetchTicTacToe(self.state.board)
              /* |> then_(v => Js.Console.log(v) |> resolve) */
              |> then_(v => self.send(Move(v)) |> resolve)
            )
            |> ignore
          ),
        )
      | Playing(Circle) =>
        ReasonReact.Update({
          ...state,
          board:
            state.board
            |> List.mapi((idx, field) => index == idx ? Some(Circle) : field),
          gameState: Playing(Cross),
        })
      | _ => ReasonReact.NoUpdate
      }
    },
  render: self =>
    <div className="App">
      <h1> (ReasonReact.string("Tic-tac-toe")) </h1>
      <Board
        data=self.state.board
        onClick=(index => self.send(Move(index)))
      />
      <p> (ReasonReact.string("One day here will be your game :)")) </p>
    </div>,
};
