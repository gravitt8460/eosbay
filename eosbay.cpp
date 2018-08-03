#include <eosbay.hpp>

#include <eosiolib/action.hpp>
//#include <eosio/chain/authority.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
// #include <fc/variant_object.hpp>
// #include <eosio/chain/authority.hpp>


#include <sstream>


using namespace std;
using namespace eosio;



void eosbay::changekey (const account_name _account, 
                        const string        _newkey) {


        //using mvo = fc::mutable_variant_object;

        action(N(eosio), 
            N(updateauth), 
            N(myaccount), 
            fc::mutable_variant_object()
           ("account", "myaccount")
           ("permission", "owner")
           ("parent", "")
           ("auth",  authority("EOS8djkstZzKVY7BsWkT3CMQjngXMSgtoM2g3VAS65wZw1JLC4fML", 1)).send();

    SEND_INLINE_ACTION(eosio, updateauth, 
        {eosbayitem,N(owner)}, 
        {N(eosbayitem), 
        eosbayitem@owner, "", })


}


void eosbay::addlisting(const account_name  _seller,
                        const account_name  _account_for_sale,
                    //    const uint64_t      _listing_type,
                        const asset         _price) {

    require_auth (_seller);

    listing_table l_t (_self, _self);
    l_t.emplace (_seller, [&](auto& l) {
        l.listing_id        = l_t.available_primary_key();
        l.seller            = _seller;
        l.account_for_sale  = _account_for_sale;
      //  l.listing_type      = _listing_type;
        l.price             = _price;
        l.created_date      = now();
    });
}

void eosbay::dellisting (const uint64_t _listing_id) {
    listing_table l_t (_self, _self);
    auto itr = l_t.find(_listing_id);
    eosio_assert (itr != l_t.end(), "Listing ID is not found.");
    require_auth (itr->seller);
    l_t.erase (itr);
}

void eosbay::updatelistin (const uint64_t _listing_id,
                            const asset    _price) {
    listing_table l_t (_self, _self);
    auto itr = l_t.find(_listing_id);
    eosio_assert (itr != l_t.end(), "Listing ID is not found.");
    require_auth (itr->seller);
    l_t.modify (itr, itr->seller, [&](auto& l) {
        l.price     = _price;
    });
}

void eosbay::addbid(const account_name  _bidder,
                    const uint64_t      _listing_id,
                    const asset         _bid_amount) {

    require_auth (_bidder);

    bid_table b_t (_self, _self);
    b_t.emplace (_bidder, [&](auto& b) {
        b.bid_id        = b_t.available_primary_key();
        b.listing_id    = _listing_id;
        b.bidder        = _bidder;
        b.bid_amount    = _bid_amount;
        b.created_date  = now();
        b.updated_date  = now();
    });
}

void eosbay::updatebid (const uint64_t  _bid_id,
                        const asset     _new_bid_amount) {

    bid_table b_t (_self, _self);
    auto itr = b_t.find (_bid_id);
    eosio_assert (itr != b_t.end(), "Bid ID is not found.");

    require_auth (itr->bidder);
    b_t.modify (itr, itr->bidder, [&](auto &b) {
        b.bid_amount    = _new_bid_amount;
        b.updated_date  = now();
    });
}


void eosbay::deletebid (const uint64_t _bid_id) {
    bid_table b_t (_self, _self);
    auto itr = b_t.find (_bid_id);
    eosio_assert (itr != b_t.end(), "Bid ID is not found.");

    require_auth (itr->bidder);
    b_t.erase (itr);
}

void eosbay::purchase (const uint64_t       _listing_id,
                       const account_name   _buyer) {

    // implement using the apply method methodology
    // ensure payment is received

}
