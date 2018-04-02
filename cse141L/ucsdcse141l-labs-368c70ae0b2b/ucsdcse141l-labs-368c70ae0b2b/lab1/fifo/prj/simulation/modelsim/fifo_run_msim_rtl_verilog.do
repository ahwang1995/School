transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -sv -work work +incdir+C:/Users/Andrew/Desktop/School/Computer\ Science/cse\ 141L/ucsdcse141l-labs-368c70ae0b2b/ucsdcse141l-labs-368c70ae0b2b/lab1/fifo/src {C:/Users/Andrew/Desktop/School/Computer Science/cse 141L/ucsdcse141l-labs-368c70ae0b2b/ucsdcse141l-labs-368c70ae0b2b/lab1/fifo/src/fifo.sv}

