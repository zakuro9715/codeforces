program main(input, output);
var s: AnsiString;
var m, i: longint;
var c: array[1..210000] of longint;
var x: longint = 0;
var v: longint;
begin
  readln(s);
  readln(m);
  for i := 1 to 210000 do
    c[i] := 0;
  for i := 1 to m do
  begin
    read(x);
    v := Length(s) - x + 2;
    c[x] := c[x] + 1;
    c[v] := c[v] + 1;
  end;

  x := 0;
  for i:= 1 to Length(s) do
  begin
    if c[i] mod 2 = 1 then
      x := x + 1;
    if x mod 2 = 0 then
      write(s[i])
    else
      write(s[Length(s) - i + 1]);
  end;
  writeln();
end.
