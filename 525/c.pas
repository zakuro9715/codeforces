program main(input, output);
var a: array[1..1000000] of integer;
var n, x, i, j, b: longint;
var ans1, ans2: longint;

function pow(v1, v2: longint): longint;
var i: integer;
var res: longint;
begin
  res := 1;
  for i := 1 to v2 do
    res := res * v1;
  pow := res;
end;

var pres: array[1..100] of integer;
procedure product(v1, v2: longint);
var i, j, x:integer;
var p1, p2: array[1..10] of integer;
begin
  for i := 1 to 100 do
    pres[i] := 0;
  for i := 1 to 10 do
  begin
    p1[i] := (v1 div pow(10, i - 1)) mod 10;
    p2[i] := (v2 div pow(10, i - 1)) mod 10;
  end;
  for i := 1 to 10 do
    for j := 1 to 10 do
    begin
      x := i + j - 1;
      pres[x] := pres[x] + p1[i] * p2[j];
      if pres[x] > 9 then
      begin
        pres[x + 1] := pres[x + 1] + pres[x] div 10; 
        pres[x] := pres[x] mod 10;
      end;
    end;
end;

procedure updateans(v1, v2: longint);
var i: integer;
begin
  product(v1, v2);
  
  for i := 1 to 8 do
  begin
    ans1 := ans1 + pres[i] * pow(10, i - 1);
    ans2 := ans2 + ans1 div pow(10, 8);
    ans1 := ans1 mod pow(10, 8); 
  end;
  for i := 9 to 16 do
    ans2 := ans2 + pres[i] * pow(10, i - 9);
  b := 0;
end;

begin
  for i := 1 to 1000000 do
    a[i] := 0;
  b := 0;
  ans1 := 0;
  ans2 := 0;

  readln(n);
  for i := 1 to n do
  begin
    read(x);
    a[x] := a[x] + 1;
  end;
  for i := 1000000 downto 2 do
  begin
    if b <> 0 then
    begin
      if a[i] >= 2 then
      begin
        updateans(b, i);
        a[i] := a[i] - 2;
      end
      else if (a[i] >= 1) and (a[i - 1] >= 1) then
      begin
        updateans(b, i - 1);
        b := 0;
        a[i] := a[i] - 1;
        a[i - 1] := a[i - 1] - 1;
      end;
    end;

    if a[i] >= 4 then
    begin
      for j := 1 to a[i] div 4 do
        updateans(i, i);
      a[i] := a[i] mod 4;
    end;

    if (a[i] >= 3) and (a[i - 1] >= 1) then
    begin
      updateans(i, i - 1);
      a[i] := 0;
      a[i - 1] := a[i - 1] - 1;
    end; 
    
    if a[i] >= 2 then
    begin
      b := i;
      a[i] := a[i] - 2;
    end
    else if (a[i] >= 1) and (a[i - 1] >= 1) then
    begin
      b := i - 1;
      a[i] := a[i] - 1;
      a[i - 1] := a[i - 1] - 1;
    end;
  end;
  if ans2 > 0 then
    begin
      write(ans2);
      for i := 8 downto 1 do
        write(ans1 div pow(10, i - 1) mod 10);
    end
  else
    write(ans1);
  writeln();
end.
