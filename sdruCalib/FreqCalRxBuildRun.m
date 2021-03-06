%% Initialization
% Baseband and RF configuration
rfRxFreq           = 2.415e9;  % Nominal RF receive center frequency
bbRxFreq           = 100;     % Received baseband sine wave frequency

%% SDRu Receiver System object
prmFreqCalibRx.RxCenterFrequency = rfRxFreq;
prmFreqCalibRx.ADCSampleRate     = 100e6;
prmFreqCalibRx.Gain              = 30;
prmFreqCalibRx.DecimationFactor  = 20;
prmFreqCalibRx.FrameLength       = 4096;
prmFreqCalibRx.TotalFrames       = 80000;
prmFreqCalibRx.RxSineFrequency   = bbRxFreq;
prmFreqCalibRx.Fs                = prmFreqCalibRx.ADCSampleRate/...
                                   prmFreqCalibRx.DecimationFactor;
prmFreqCalibRx.OutputDataType    = 'double';

%% Coarse Freq Offset estimation 
prmFreqCalibRx.FocFFTSize        = 2048;

%% Spectrum Analyzer 
prmFreqCalibRx.SpeAnaFFTLength   = 8192;

compilesdru('FreqCalRx','mex','-args',{coder.Constant(prmFreqCalibRx)})

%Run
FreqCalRx_mex(prmFreqCalibRx);

