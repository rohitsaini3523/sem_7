struct InputInfo {
        int num1;
        
};


struct OutputInfo {
        int result;
};



program RPCPROGRAM {
        version FACTVERSION {
                struct OutputInfo performAddition(struct InputInfo iInfo)=1;
                }=1;
	
	
}=22222222;
