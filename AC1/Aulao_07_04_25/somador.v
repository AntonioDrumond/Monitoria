module Main;
	reg [3 : 0] x;
	reg [3 : 0] y;
	wire [3 : 0] c;
	wire [3 : 0] s;

	fullAdder fa0 (c[0], s[0], x[0], y[0], 1'b0);
	fullAdder fa1 (c[1], s[1], x[1], y[1], c[0]);
	fullAdder fa2 (c[2], s[2], x[2], y[2], c[1]);
	fullAdder fa3 (c[3], s[3], x[3], y[3], c[2]);
	
	initial 
	begin: main
		$monitor("%b + %b = %b", x, y, s);
		
		x = 4'b0011; 
		y = 4'b0101;
		
		#1 
		
		x = 4'b1100; 
		y = 4'b0110;
		
		#1
		
		x = 4'b1111; 
		y = 4'b1111;
	end
endmodule

module halfAdder (output s1, s0, input a, b);
	xor XOR1 (s0, a, b);
	and AND1 (s1, a, b);
endmodule

module fullAdder (output s1, s0, input a, b, cIn);
	wire s, c1, c2;

	halfAdder ha1 (c1, s, a, b);
	halfAdder ha2 (c2, s0, s, cIn);
	
	or OR1 (s1, c1, c2);
endmodule

