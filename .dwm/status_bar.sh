#!/usr/bin/env bash

status_bar() {
    ram_usage="[R: $(free -h --si | grep Mem | awk '{print ($3)}')]"

    todays_date="[D: $(date +"%b %d, %Y %a %I:%M%p")]"

    battery_level="[B: $(cat /sys/class/power_supply/BAT1/capacity)]"

    xsetroot -name "$ram_usage | $todays_date | $battery_level"
}

while true; do
    status_bar
    sleep 1
done
