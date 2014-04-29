function mat = rotationMatrix(roll,pitch,yaw)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

cr = cos(roll);     sr = sin(roll); 
cp = cos(pitch);    sp = sin(pitch);
cy = cos(yaw);      sy = sin(yaw);

CY = [cp,0,-sp;0,1,0;sp,0,cp];
CX = [1,0,0;0,cr,sr;0,-sr,cr];
CZ = [cy,sy,0;-sy,cy,0;0,0,1];

mat = CZ*CX*CY;

end

