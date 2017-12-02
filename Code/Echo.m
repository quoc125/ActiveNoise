%JOSU SEBASTIAN UDAONDO

clear all
clc
close all
n=0:9999;%NUMBER OF SAMPLES
T=1/8000;%SAMPLING FREQUENCY
f=1000;%FREQUENCY OF SIGNAL
fil=[];% ARRAY USED FOR STORING DESIRED SIGNAL

exact1=cos(2.pi.f.n.T);%SIGNAL

delay=0.8.cos(2.pi.f.(n-200).T);%DELAYED SIGNAL

delay=exact1+delay;%CORRUPTED SIGNAL

d1=[];%USED TO FIND EXACT 

nu=0.1%CHOSEN STEP SIZE

%%%%%%%%%%%%%%%%%%%%%%WEIGHTS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ww=[0,0,0]%INTIAL VALUES
ww1=[0,0,0]%INTIAL VALUES
ww2=[0,0,0]%INITAL VALUES


final=[]%USED FOR y(n)


%HA ALGORITHIM
for i=3:10000
en(i)=exact1(i)-ww(i)delay(i)-ww1(i)delay(i-1)-ww2(i)delay(i-2);%ERROR SGNAL S-(S+E)
nu=2(delay(i)^2+delay(i-1)^2+delay(i-2)^2);%STEP SIZE USED 
nu=1/nu%PART OF THE ALGO FOR STEP SIZE
%CALCULATING WEIGHTS
ww(1+i)=(ww(i)+nuen(i)delay(i));
ww1(1+i)=ww1(i)+nuen(i)delay(i-1);
ww2(1+i)=(ww2(i)+nuen(i)delay(i-2));
end


%%%%%%%%%%%FINDING y(n) USING FINAL WEIGHTS FOUND%%%%%%%%%%%%%%%%%%%%%%
fil=[fil;ww(10000)];
fil=[fil;ww1(10000)];
fil=[fil;ww2(10000)];

%%%%%%%%%%%%%%%%%%%%%%%CALCULATING THE FIRST THREE ITERATIONS OF FINAL
%%%%%%%%%%%%%%%%%%%%%%%ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
final=[final;fil(1)delay(1)];
final=[final;fil(1)delay(2)+fil(2)delay(1)];
final=[final;fil(1)delay(3)+fil(2)delay(2)+fil(3)delay(1)]

%%%%%%%%%%%%%%CALCULATING THE FINAL ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for i=4:10000
    a=fil(1)delay(i)+fil(2)delay(i-1)+fil(3)delay(i-2);
    final=[final;a];
end



%%%%%%%%%%CREATING THE AUDIO OF CLEAN SIGNAL%%%%%%%%%%%%%%
filename = '1000matlab.wav';
audiowrite(filename,final,1/T);

%plots
n=0:9999
n=n*T; %USED TO KNOW WHAT TIME IT IS

stem(n,exact1);
hold on
plot(n,final,'y');
hold on
plot(n,delay,'r')