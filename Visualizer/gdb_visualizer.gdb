define visualize_array
  set $size = $arg0
  set $ptr = $arg1
  print *(int(*)[$size]) $ptr
end
