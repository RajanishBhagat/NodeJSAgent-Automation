/*-----------------------------------------------------------------------------
    Name: flow
    Recorded By: netstorm
    Date of recording: 08/10/2016 05:41:12
    Flow details:
    Build details: 4.1.6 (build# 6)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ns_string.h"

long long current_timestamp();

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    return milliseconds;
    }

void updateCorrelationId(){
    char buf[32];
    sprintf(buf, "Nsecomm-CID-%lld", current_timestamp());
#if NS_DEBUG_ON 
    printf("*********current time: %s******\n", buf);
#endif
    ns_save_string(buf, "corrID");
}

void flow()
{   
    ns_start_transaction("Home");
    updateCorrelationId();
    ns_web_url ("nsecomm",
        "URL=http://127.0.0.1/nsecomm?storeNum=240,244,1504,1426,1068",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
         "HEADER=Cavission:Noida",
          "HEADER=DNT:2",
        "PreSnapshot=webpage_1470830999593.png",
        "Snapshot=webpage_1470831005257.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", END_INLINE
    );

     ns_end_transaction("Home", NS_AUTO_STATUS);

    ns_page_think_time(2.606);
    
    ns_start_transaction("CheckOut");
    updateCorrelationId();
    ns_web_url ("checkOutAndPlaceOrder",
        "URL=http://127.0.0.1/nsecomm/checkOutAndPlaceOrder?sleepTimeForCC=6&sleepTimeForValidate=40&level=5",
        "HEADER=Upgrade-Insecure-Requests:1",
         "HEADER=correlation-id: {corrID}",
        "HEADER=Accept-Language:en-in",
        "PreSnapshot=webpage_1470831011529.png",
        "Snapshot=webpage_1470831012435.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", "HEADER=If-Modified-Since:Wed, 10 Aug 2016 11:23:40 GMT", "HEADER=If-None-Match:W/\"1cec-3583235245\"", END_INLINE
    );
     ns_end_transaction("CheckOut", NS_AUTO_STATUS);

/*    ns_page_think_time(2.696); 
ns_start_transaction("CheckInventory");
    updateCorrelationId();
 ns_web_url ("checkInventory",
        "URL=http://127.0.0.1/nsecomm/checkInventory",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
         "HEADER=correlation-id: {corrID}",
        "PreSnapshot=webpage_1470831040199.png",
        "Snapshot=webpage_1470831041383.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", "HEADER=If-Modified-Since:Wed, 10 Aug 2016 11:23:40 GMT", "HEADER=If-None-Match:W/\"1cec-3583235245\"", END_INLINE
    );

    ns_end_transaction("CheckInventory", NS_AUTO_STATUS);*/

    ns_page_think_time(2.354);
    
    ns_start_transaction("ManyTier");
    updateCorrelationId();
    ns_web_url ("manyTier",
        "URL=http://127.0.0.1/nsecomm/manyTier",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
         "HEADER=correlation-id: {corrID}",
        "PreSnapshot=webpage_1470831051145.png",
        "Snapshot=webpage_1470831052137.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", "HEADER=If-Modified-Since:Wed, 10 Aug 2016 11:23:40 GMT", "HEADER=If-None-Match:W/\"1cec-3583235245\"", END_INLINE
    );
     ns_end_transaction("ManyTier", NS_AUTO_STATUS);

    ns_page_think_time(2.724);
   
    ns_start_transaction("MongoDB");
    updateCorrelationId();
    ns_web_url ("mongodb",
        "URL=http://127.0.0.1/nsecomm/mongodb",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "PreSnapshot=webpage_1470831058825.png",
        "Snapshot=webpage_1470831059932.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", "HEADER=If-Modified-Since:Wed, 10 Aug 2016 11:23:40 GMT", "HEADER=If-None-Match:W/\"1cec-3583235245\"", END_INLINE
    );
    ns_end_transaction("MongoDB", NS_AUTO_STATUS);

    ns_page_think_time(2.471);
   ns_start_transaction("Redis");
   updateCorrelationId();
   ns_web_url ("redis",
        "URL=http://127.0.0.1/nsecomm/redis",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "PreSnapshot=webpage_1470831480114.png",
        "Snapshot=webpage_1470831481081.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=Accept-Language:en-in", "HEADER=If-Modified-Since:Wed, 10 Aug 2016 11:23:40 GMT", "HEADER=If-None-Match:W/\"1cec-3583235245\"", END_INLINE
    );
    ns_end_transaction("Redis", NS_AUTO_STATUS);

    ns_page_think_time(2.076);
ns_start_transaction("MemCache");
 updateCorrelationId();
 ns_web_url ("memcache",
        "URL=http://127.0.0.1/nsecomm/memcache",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-us",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1491909056207.png",
        "Snapshot=webpage_1491909056609.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-643270210\"", "HEADER=If-Modified-Since:Mon, 10 Apr 2017 13:41:27 GMT", "HEADER=Accept-Language:en-us", "COOKIE=connect.sid", END_INLINE
    );
 ns_end_transaction("MemCache", NS_AUTO_STATUS);
 ns_page_think_time(2.359); 

    ns_start_transaction("zoo");
     updateCorrelationId();
    ns_web_url ("zoo",
        "URL=http://127.0.0.1/nsecomm/zoo",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-us",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1496248213831.png",
        "Snapshot=webpage_1496248214079.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-1598519013\"", "HEADER=If-Modified-Since:Wed, 31 May 2017 15:29:40 GMT", "HEADER=Accept-Language:en-us", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("zoo", NS_AUTO_STATUS); 
    ns_page_think_time(2.359);

    ns_start_transaction("net");
    ns_web_url ("net",
        "URL=http://127.0.0.1/nsecomm/net",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1523444562449.png",
        "Snapshot=webpage_1523444562975.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-3326998768\"", "HEADER=If-Modified-Since:Mon, 26 Feb 2018 13:39:29 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("net", NS_AUTO_STATUS);
    ns_page_think_time(2.008);
   
/*    ns_start_transaction("udp");
    updateCorrelationId();
    ns_web_url ("udp",
        "URL=http://127.0.0.1/nsecomm/udp",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513752073815.png",
        "Snapshot=webpage_1513752074594.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-4149953168\"", "HEADER=If-Modified-Since:Tue, 19 Dec 2017 07:50:48 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("udp", NS_AUTO_STATUS);
    ns_page_think_time(2.216);*/
   
/*    ns_start_transaction("timer");
    updateCorrelationId();
    ns_web_url ("timer",
        "URL=http://127.0.0.1/nsecomm/timer",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513752067282.png",
        "Snapshot=webpage_1513752069972.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-4149953168\"", "HEADER=If-Modified-Since:Tue, 19 Dec 2017 07:50:48 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("timer", NS_AUTO_STATUS);
    ns_page_think_time(2.133);*/
  
/*    ns_start_transaction("reversedns");
    updateCorrelationId();
     ns_web_url ("reversedns",
        "URL=http://127.0.0.1/nsecomm/reversedns",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513752034683.png",
        "Snapshot=webpage_1513752035272.png",
    );

    ns_end_transaction("reversedns", NS_AUTO_STATUS);

    ns_page_think_time(2.133);

    ns_start_transaction("dns");
     updateCorrelationId();
    ns_web_url ("dns",
        "URL=http://127.0.0.1/nsecomm/dns",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513751994269.png",
        "Snapshot=webpage_1513751994811.png",
    );

    ns_end_transaction("dns", NS_AUTO_STATUS);
    ns_page_think_time(14.029);

    ns_start_transaction("crypto");
    updateCorrelationId();
    ns_web_url ("crypto",
        "URL=http://127.0.0.1/nsecomm/crypto",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513751988796.png",
        "Snapshot=webpage_1513751989808.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-4149953168\"", "HEADER=If-Modified-Since:Tue, 19 Dec 2017 07:50:48 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("crypto", NS_AUTO_STATUS);
    ns_page_think_time(2.484);*/

/*    ns_web_url ("zlib",
        "URL=http://127.0.0.1/nsecomm/zlib",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513751978970.png",
        "Snapshot=webpage_1513751979868.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-4149953168\"", "HEADER=If-Modified-Since:Tue, 19 Dec 2017 07:50:48 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("zlib", NS_AUTO_STATUS);
    ns_page_think_time(1.902);
  
      ns_start_transaction("uzlib");
    updateCorrelationId();
    ns_web_url ("uzlib",
        "URL=http://127.0.0.1/nsecomm/uzlib",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-in",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1513751983606.png",
        "Snapshot=webpage_1513751984429.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/logo.png", "HEADER=If-None-Match:W/\"1cec-4149953168\"", "HEADER=If-Modified-Since:Tue, 19 Dec 2017 07:50:48 GMT", "HEADER=Accept-Language:en-in", "COOKIE=connect.sid", END_INLINE
    );

    ns_end_transaction("uzlib", NS_AUTO_STATUS);
    ns_page_think_time(2.348);*/

/*   ns_start_transaction("home");
     updateCorrelationId();

    ns_web_url ("home",
        //"URL=http://127.0.0.1/nsecomm/home",
        "URL=http://192.208.179.130:3000/nsecomm/home",
        "HEADER=Upgrade-Insecure-Requests:1",
        "HEADER=Accept-Language:en-us",
        "HEADER=correlation-id: {corrID}",
        "COOKIE=connect.sid",
        "PreSnapshot=webpage_1484646935727.png",
        "Snapshot=webpage_1484646937473.png",
        INLINE_URLS,
            "URL=http://127.0.0.1/images/nsecomlogo.png", "HEADER=Accept-Language:en-us", "COOKIE=connect.sid", END_INLINE
    );

   ns_end_transaction("home", NS_AUTO_STATUS);*/

}
