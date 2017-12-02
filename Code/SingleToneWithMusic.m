%%%% Josu S UDAONDO  
clear all 
clc
[y,Fs] = audioread('44.1kfs.wav');%%%%%TAKING SIGNAL

music=[];
music=[y(1);music];%%first value
j=44100/1470;%%number of times i should skip                  
k=1;
L=0;
T=1/1470;
for i=1:1:size(y) 
   L=L+1;
   if L==j
       music=[y(i);music];
       L=0;
   end
end


filename = 'pure.wav';
audiowrite(filename,music,1/T);

%%%%%%%%%%%%%%%%%%%%%%%%%%ADDING THE RANDOM TONE%%%%%%%%%%%%%%%%%%%%%%%%%
Samples=size(music)-1;
n=0:Samples;
f=210;%FREQUENCY OF SIGNAL
phi=0%%PHASE
A=.1;%%%AMPLITUDE

exact1=A*cos(2.*pi.*f.*n.*T + phi);%SIGNAL
c=exact1;
pure=music;

music=music+c';%%sound with noise

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%FINDING THE RANDOM TONE%%%%%%%%%%%%%%%%%
n=0:Samples;%NUMBER OF SAMPLES
T=1/1470;%SAMPLING FREQUENCY

fil=[];% ARRAY USED FOR STORING DESIRED SIGNAL
n=0:Samples;%NUMBER OF SAMPLES
T=1/1470;%SAMPLING FREQUENCY

k=max(music);%%% FIRST SAMPLE

filename = 'corrupted.wav';
audiowrite(filename,music,1/T);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ALGORITHIM%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
found=music;
fil=[];% ARRAY USED FOR STORING DESIRED SIGNAL

d1=[];%USED TO FIND EXACT 

nu=0.1;%CHOSEN STEP SIZE

%%%%%%%%%%%%%%%%%%%%%%WEIGHTS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ww=[0,0,0,0,0];%INTIAL VALUES
ww1=[0,0,0,0,0];%INTIAL VALUES
ww2=[0,0,0,0,0];%INITAL VALUES
ww3=[0,0,0,0,0];%INITAL VALUES
final=[];%USED FOR y(n)


%HA ALGORITHIM
for i=5:(Samples+1)
en(i)=pure(i)-ww(i)*found(i)-ww1(i)*found(i-1)-ww2(i)*found(i-2)-ww3(i)*found(i-3);%ERROR SGNAL S-(S+E)
nu=2*(found(i)^2+found(i-1)^2+found(i-2)^2+found(i-3)^2);%STEP SIZE USED 
nu=1/nu;%PART OF THE ALGO FOR STEP SIZE
%CALCULATING WEIGHTS
ww(1+i)=(ww(i)+nu*en(i)*found(i));
ww1(1+i)=ww1(i)+nu*en(i)*found(i-1);
ww2(1+i)=(ww2(i)+nu*en(i)*found(i-2));
ww3(1+i)=(ww3(i)+nu*en(i)*found(i-3));
end  

x=Samples+1
%%%%%%%%%%%FINDING y(n) USING FINAL WEIGHTS FOUND%%%%%%%%%%%%%%%%%%%%%%
fil=[fil;ww(x)];
fil=[fil;ww1(x)];
fil=[fil;ww2(x)];
fil=[fil;ww3(x)];
%%%%%%%%%%%%%%%%%%%%%%%CALCULATING THE FIRST THREE ITERATIONS OF FINAL
%%%%%%%%%%%%%%%%%%%%%%%ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
final=[final;fil(1)*found(1)];
final=[final;fil(1)*found(2)+fil(2)*found(1)];
final=[final;fil(1)*found(3)+fil(2)*found(2)+fil(3)*found(1)];
final=[final;fil(1)*found(3)+fil(2)*found(2)+fil(3)*found(1)+fil(4)*found(1)];
%%%%%%%%%%%%%%CALCULATING THE FINAL ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for i=5:(Samples+1)
    a=fil(1)*found(i)+fil(2)*found(i-1)+fil(3)*found(i-2)+fil(4)*found(i-3);
    final=[final;a];
end



%%%%%%%%%%CREATING THE AUDIO OF CLEAN SIGNAL%%%%%%%%%%%%%%
filename = 'final.wav';
audiowrite(filename,final,1/T);

plot(n,final);
