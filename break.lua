params = ""
for i=1, 1000 do
  params = params .. "blahblah "
end
local file, err = io.popen("./ex10 " .. params)
for x in file.lines(file) do
  print(x)
end

print(err)
