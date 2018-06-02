[%bs.raw {|require('./Field.css')|}];

let component = ReasonReact.statelessComponent("Field");

open Core

let make = (~data, ~onClick, _children) => {
  ...component,
  render: _self =>
    <div className="Field" onClick>
     (ReasonReact.string(fieldToStr(data)))
    </div>
};
