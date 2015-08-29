function [ speedups ] = q1( alpha, p )
% This function will produce a plot of speedup as a function of number of cores (S(p))
% alpha is the fraction of serial work
% p is the number of total cores

speedups = zeros(1, p);
for i = 1:p
    speedups(i) = 1 / ( alpha + ( 1 - alpha ) / i );
end

plot(speedups, 'k-');
title( 'Speed up due to strong scaling' );
xlabel( 'Number of parallel processors' );
ylabel( 'Speedup S(p)' );

end