program main(input, output);
var a: array['a'..'z'] of integer;
var s: string;
var n, i, ans: integer;
var c: char;
begin
  ans := 0;
  for c := 'a' to 'z' do
    a[c] := 0;
  readln(n);
  readln(s);
  for i := 1 to Length(s) do
  begin
    c := char(byte(s[i]) - byte('A') + byte('a'));
    if i mod 2 = 1 then
      a[s[i]] := a[s[i]] + 1
    else if a[c] <= 0 then
      ans := ans + 1
    else
      a[c] := a[c] - 1
  end;
  writeln(ans);
end.
