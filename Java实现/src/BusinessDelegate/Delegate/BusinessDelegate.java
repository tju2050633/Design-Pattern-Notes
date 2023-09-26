package BusinessDelegate.Delegate;

import BusinessDelegate.Business.BusinessLookUp;
import BusinessDelegate.Business.Service.BusinessService;

public class BusinessDelegate {
    private BusinessLookUp lookupService = new BusinessLookUp();
    private BusinessService businessService;
    private String serviceType;
    
    public void setServiceType(String serviceType) {
        this.serviceType = serviceType;
    }
    
    public void doTask() {
        businessService = lookupService.getBusinessService(serviceType);
        businessService.doProcessing();
    }
}
