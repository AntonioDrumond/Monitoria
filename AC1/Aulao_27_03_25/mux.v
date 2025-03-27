module mux (output s, input a, b, select);
  assign s = (a & ~select) + (b & select);
endmodule

module tests;
  reg a, b, select;
  wire s;

  mux m (s, a, b, select);

  initial begin: main

    $monitor("a = %b  |  b = %b  |  select = %b  |  s = %b", a, b, select, s);
    a = 1; b = 0; select = 0;
    #2;

    a = 1; b = 0; select = 1;
    #2;
    // $display("a = %b  |  b = %b  |  select = %b  |  s = %b", a, b, select, s);

  end
endmodule
