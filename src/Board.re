[%bs.raw {|require('./Board.css')|}];

let component = ReasonReact.statelessComponent("Board");


let make = (~data, ~onClick, _children) => {
  ...component,
  render: _self =>
    <div className="Board">
      (data |>
        List.mapi((idx, field) =>
          <Field key=string_of_int(idx) data=field onClick=(_e => onClick(idx)) />
        )
        |> Array.of_list
        |> ReasonReact.array
      )
    </div>
};
