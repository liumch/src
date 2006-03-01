ex[e_]:=(Sqrt[1+e^2]-1-
	Log[(1+Sqrt[1+e^2])/2])/2;
Series[ex[e],{e,0,4}];
bo[e_]:=e^2/8;
no[e_]:=Sqrt[1+e^2/4]-1;
fu[e_]:=-Log[1-e^2/4]/2;
Plot[ex[e],{e,0,1}];
Plot[bo[e],{e,0,1},
	PlotStyle->Dashing[{0.05,0.05}]];
Plot[no[e],{e,0,1},
	PlotStyle->Dashing[{0.01,0.01}]];
Plot[fu[e],{e,0,1},
	PlotStyle->Dashing[{0.01,0.05,0.05,0.05}]];
Show[%6,%7,%8,%9,Frame->True,
	FrameLabel->{"e","y","",""},
	AspectRatio->1/2,RotateLabel->False,
	FrameTicks->{Automatic,{0,0.05,0.1,0.15}},
	GridLines->{Automatic,{0.025,0.05,0.075,0.1,0.125}}];
Display["junk_ma.eps", %, "EPS"];
