let requestConfig =
  Fetch.RequestInit.make(
    ~headers=
      Fetch.HeadersInit.make({
        "X-Mashape-Key": "IOcLqZVBNsmshtobOT2TytaskZTnp1OMseHjsnSaG7KfmE6n8X",
        "Accept": "application/json",
      }),
    (),
  );

let decodeResponse = json => Json.Decode.(json |> field("recommendation", int));

let fetchTicTacToe = board => {
  let boardState =
    List.fold_left(
      (res, field) => res ++ Core.fieldToStr(field),
      "",
      board,
    );

  let url =
    "https://stujo-tic-tac-toe-stujo-v1.p.mashape.com/" ++ boardState ++ "/O";
    Js.Promise.(
      Fetch.fetchWithInit(url, requestConfig)
      |> then_(Fetch.Response.text)
      |> then_(text => text |> Json.parseOrRaise |> decodeResponse |> resolve)
    )
};