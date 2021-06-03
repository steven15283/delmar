PASS:
-----------------------------------
data x = 1 .
begin
in x .
loop [ x < 5 ]
begin
  out x . 
x = x + 1 . 
end.
end

-----------------------------------
begin
data x = 1 .
data y = 2 .
out x + y.
end

-----------------------------------
data x = 1 .
data y = 2 .
begin
  data z = 3 .
  begin 
    out 1 .
  end 
  out z .
end
-----------------------------------
data x = 1 .
data y = 2 .
begin
  in x .
  out x + 2 / ( 2 - y ) .
end
-----------------------------------
begin
  out 1 .
end
-----------------------------------
data x = 1 .
begin
  read x .
  out x .
end
-----------------------------------
data x = 1 .
begin
  x = 10 .
  out x .
end
-----------------------------------
data x = 1 .
begin
  in x .
  out x + 1 - 1 .
end
-----------------------------------
data x = 1 .
begin
  in x .
  iffy [ x < 10 ] then
    iffy [ x > > 0 ] then 
      out x . . .
end
-----------------------------------
data x = 1 .
begin
in x .
loop [ x > 0 ]
  begin
    out x .
    x = x - 1 .
  end .
end
-----------------------------------
data x = 1 .
begin
  in x .
  iffy [ x < 9 / 2 - 4 ] then
    x = * x . .
  out x .
end

-----------------------------------
data x = 1 .
begin
  in x .
  out x / 5 + * 5 + 2 * ( 2 - 1 ) .
end
-----------------------------------
data x = 1 .
begin
  in x .
  iffy [ x < 0 ] then
    x = * x . .
  out x .
end
-----------------------------------

Fail:
-----------------------------------
start
  out * * * 1 ;
stop

//my scanner doesnt recognize start and stop as keywords
-----------------------------------

data x = 1 .
data y = 2 .
begin
  in x .
  loop [ x > 0 ]
  begin
    y = x .
    loop [ y > 0 ]
    begin
      out y .
      y = y - 2 .
    end .
    x = x - 1 .
  end .
out y .
end

// I enter -2 and output 2 back. I input -1 and i get 2 back. I input -3 and i get 2 back. 