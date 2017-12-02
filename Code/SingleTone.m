%JOSU S UDAONDO 


%%finding the frequency of random tone with noise 

clear all
clc
close all
n=0:99;%NUMBER OF SAMPLES
T=1/1470;%SAMPLING FREQUENCY

fil=[];% ARRAY USED FOR STORING DESIRED SIGNAL

int=7

f=1470/int;%FREQUENCY OF SIGNAL

phi=pi/4;

A=2047;

exact1=A+A*cos(2.*pi.*f.*n.*T + phi);%SIGNAL
c=exact1;

% delay=0.8.*cos(2.*pi.*f.*(n-32).*T);%DELAYED SIGNAL
% 
% delay=exact1+delay;%CORRUPTED SIGNAL


%%%%%%%%%%%%%%%ALLL BEFORE THIS IS ASSUMED UNKNOWN%%%%%%%%%%%%%%%%%%%%%%%%

%all i have is delay% n number of samples and T%%%

n=0:99;%NUMBER OF SAMPLES
T=1/1470;%SAMPLING FREQUENCY

k=max(c);%%% FIRST SAMPLE
for i=2:99 %GO THROUGH DATA
    if k==c(i) %CHECK IF THE POINT HAS REPEATED
        L=i;
        break
    end
end
 

z=0;%counter 

 
for i=L+1:99 %GO THROUGH DATA
    if c(i)>=(k-0.005*4095) && c(i)<=(k+0.005*4095)%%CHECK IF THE POINT HAS REPEATED
        z=z+1;%IF SO INCREMENT Z
    end
    
    if z==1 %IF SAMPLE HAS NOT OCCURED MORE THAN ONCE 
        break
    end 
end
 

%%%% I IS NOW THE NUMBER OF SAMPLES THAT HAS PASSED SINCE THEN

time=(i-L)*T%%%TIME PASSED SUBCTRACT ONE DUE TO LOOP

Frequency=1/time %%% FREQUENCY NOW FOUND

%%%%%MUST BE MULTIPLES OF SAMPLING FREQUENCY%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%FINDING AMPLITUDE n PHASE%%%%%%%%%%%%%%%%%%%%%%%%%%

%%KNOWN VALUES
n=0:99;%NUMBER OF SAMPLES
T=1/1470;%SAMPLING FREQUENCY
Frequency;%FREQUENCY FOUND


Amplitude=max(c)/2; %%%%%%%max will be equal to Acos(0) or just A

x=(1/(2*Frequency))/T%%%% finding pi
x=floor(x)
E2=c(x);%%%%%Acos(pi+phi)

phase=abs(acos(-E2))/2 %%%% i need to take magnitude to find phase




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ALGORITHIM%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
found=Amplitude*cos(2.*pi.*Frequency.*n.*T + phase)/2 + Amplitude/2;%% cos i found

fil=[];% ARRAY USED FOR STORING DESIRED SIGNAL

d1=[];%USED TO FIND EXACT 

nu=0.1;%CHOSEN STEP SIZE

%%%%%%%%%%%%%%%%%%%%%%WEIGHTS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ww=[0,0,0];%INTIAL VALUES
ww1=[0,0,0];%INTIAL VALUES
ww2=[0,0,0];%INITAL VALUES


final=[];%USED FOR y(n)


%HA ALGORITHIM
for i=3:100
en(i)=found(i)-ww(i)*found(i)-ww1(i)*found(i-1)-ww2(i)*found(i-2);%ERROR SGNAL S-(S+E)
nu=2*(found(i)^2+found(i-1)^2+found(i-2)^2);%STEP SIZE USED 
nu=1/nu;%PART OF THE ALGO FOR STEP SIZE
%CALCULATING WEIGHTS
ww(1+i)=(ww(i)+nu*en(i)*found(i));
ww1(1+i)=ww1(i)+nu*en(i)*found(i-1);
ww2(1+i)=(ww2(i)+nu*en(i)*found(i-2));
end  


%%%%%%%%%%%FINDING y(n) USING FINAL WEIGHTS FOUND%%%%%%%%%%%%%%%%%%%%%%
fil=[fil;-ww(100)];
fil=[fil;-ww1(100)];
fil=[fil;-ww2(100)];

%%%%%%%%%%%%%%%%%%%%%%%CALCULATING THE FIRST THREE ITERATIONS OF FINAL
%%%%%%%%%%%%%%%%%%%%%%%ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
final=[final;fil(1)*found(1)];
final=[final;fil(1)*found(2)+fil(2)*found(1)];
final=[final;fil(1)*found(3)+fil(2)*found(2)+fil(3)*found(1)];

%%%%%%%%%%%%%%CALCULATING THE FINAL ANSWER%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for i=4:100
    a=fil(1)*found(i)+fil(2)*found(i-1)+fil(3)*found(i-2);
    final=[final;a];
end



%%%%%%%%%%CREATING THE AUDIO OF CLEAN SIGNAL%%%%%%%%%%%%%%
% filename = '1000matlab.wav';
% audiowrite(filename,final,1/T);

%plots
n=0:99;
n=n*T; %USED TO KNOW WHAT TIME IT IS

final=final+Amplitude;
plot(n,c);
hold on
plot(n,final,'r');
        
